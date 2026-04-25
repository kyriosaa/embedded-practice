import { useState, useRef, useEffect } from 'react';
import QRCode from 'qrcode';
import './css/PhotoDisplay.css';

function PhotoDisplay({ photos, selectedFrame, onRetake }) {
  const [showQR, setShowQR] = useState(false);
  const [qrCodeUrl, setQrCodeUrl] = useState('');
  const [downloadUrl, setDownloadUrl] = useState('');
  const [isUploading, setIsUploading] = useState(false);
  const compositeCanvasRef = useRef(null);

  // Use Vite's environment variable syntax
  const IMGBB_API_KEY = import.meta.env.VITE_IMGBB_API_KEY;

  const getFrameImage = (frameId) => {
    return `/src/assets/${frameId}.png`;
  };

  const createCompositeImage = async () => {
    const canvas = compositeCanvasRef.current;
    const ctx = canvas.getContext('2d');
    
    // Set canvas size to match frame
    canvas.width = 300;
    canvas.height = 600;
    
    // Load frame image
    const frameImg = new Image();
    frameImg.crossOrigin = 'anonymous';
    
    return new Promise((resolve) => {
      frameImg.onload = async () => {
        // Draw frame background
        ctx.drawImage(frameImg, 0, 0, 300, 600);
        
        // Draw photos
        const photoPromises = photos.map((photoSrc, index) => {
          return new Promise((photoResolve) => {
            const img = new Image();
            img.crossOrigin = 'anonymous';
            img.onload = () => {
              // Calculate photo position and size
              const photoSlotHeight = 250;
              const photoSlotY = 50 + (index * (photoSlotHeight + 15));
              const photoSlotX = 50;
              const photoSlotWidth = 200;
              
              // Calculate aspect ratio to fit within slot
              const imgAspect = img.width / img.height;
              const slotAspect = photoSlotWidth / photoSlotHeight;
              
              let drawWidth, drawHeight, drawX, drawY;
              
              if (imgAspect > slotAspect) {
                // Image is wider, fit to width
                drawWidth = photoSlotWidth;
                drawHeight = photoSlotWidth / imgAspect;
              } else {
                // Image is taller, fit to height
                drawHeight = photoSlotHeight;
                drawWidth = photoSlotHeight * imgAspect;
              }
              
              // Center the image in the slot
              drawX = photoSlotX + (photoSlotWidth - drawWidth) / 2;
              drawY = photoSlotY + (photoSlotHeight - drawHeight) / 2;
              
              ctx.drawImage(img, drawX, drawY, drawWidth, drawHeight);
              photoResolve();
            };
            img.src = photoSrc;
          });
        });
        
        await Promise.all(photoPromises);
        
        // Convert canvas to blob
        canvas.toBlob((blob) => {
          resolve(blob);
        }, 'image/png');
      };
      
      frameImg.src = getFrameImage(selectedFrame);
    });
  };

  const uploadToImgBB = async (imageBlob) => {
    if (!IMGBB_API_KEY) {
      throw new Error('ImgBB API key not found. Please add VITE_IMGBB_API_KEY to your .env file.');
    }

    const formData = new FormData();
    formData.append('image', imageBlob);

    try {
      const response = await fetch(`https://api.imgbb.com/1/upload?key=${IMGBB_API_KEY}`, {
        method: 'POST',
        body: formData
      });

      const data = await response.json();
      
      if (data.success) {
        return data.data.url; // Direct image URL
      } else {
        throw new Error('Upload failed: ' + data.error.message);
      }
    } catch (error) {
      console.error('Error uploading to ImgBB:', error);
      throw error;
    }
  };

  const handleDownload = async () => {
    try {
      setIsUploading(true);
      
      // Create composite image
      const imageBlob = await createCompositeImage();
      
      // Upload to ImgBB
      const imageUrl = await uploadToImgBB(imageBlob);
      setDownloadUrl(imageUrl);
      
      // Generate QR code with the ImgBB URL
      const qrCodeDataUrl = await QRCode.toDataURL(imageUrl, {
        width: 200,
        margin: 2,
        color: {
          dark: '#000000',
          light: '#FFFFFF'
        }
      });
      
      setQrCodeUrl(qrCodeDataUrl);
      setShowQR(true);
      setIsUploading(false);
    } catch (error) {
      console.error('Error generating QR code:', error);
      setIsUploading(false);
      alert('Error creating download link. Please try again.');
    }
  };

  const handleDirectDownload = async () => {
    if (downloadUrl) {
      // For direct download, we'll create the image again and download it
      try {
        const imageBlob = await createCompositeImage();
        const localUrl = URL.createObjectURL(imageBlob);
        
        const link = document.createElement('a');
        link.href = localUrl;
        link.download = `photobooth-${Date.now()}.png`;
        document.body.appendChild(link);
        link.click();
        document.body.removeChild(link);
        
        // Clean up
        URL.revokeObjectURL(localUrl);
      } catch (error) {
        console.error('Error downloading image:', error);
        alert('Error downloading image. Please try again.');
      }
    }
  };

  const closeQR = () => {
    setShowQR(false);
    setDownloadUrl('');
  };

  return (
    <div className="photo-display">
      <h2>Your Photo Strip!</h2>
      
      <div className="photo-strip">
        <div className="frame-container">
          <img 
            src={getFrameImage(selectedFrame)} 
            alt="Frame" 
            className="frame-background"
          />
          <div className="photos-container">
            {photos.map((photo, index) => (
              <div key={index} className="photo-slot">
                <img 
                  src={photo} 
                  alt={`Photo ${index + 1}`}
                  className="captured-photo"
                />
              </div>
            ))}
          </div>
        </div>
      </div>
      
      <div className="action-buttons">
        <button className="retake-button" onClick={onRetake}>
          Take New Photos
        </button>
        <button 
          className="download-button" 
          onClick={handleDownload}
          disabled={isUploading}
        >
          {isUploading ? '⏳ Creating QR...' : '📱 Get QR Code'}
        </button>
      </div>

      {/* Hidden canvas for composite image creation */}
      <canvas 
        ref={compositeCanvasRef} 
        style={{ display: 'none' }}
      />

      {/* QR Code Modal */}
      {showQR && (
        <div className="qr-modal">
          <div className="qr-content">
            <button className="close-button" onClick={closeQR}>×</button>
            <h3>Scan to Download</h3>
            <div className="qr-code-container">
              <img src={qrCodeUrl} alt="QR Code" className="qr-code" />
            </div>
            <p className="qr-instructions">
              Scan this QR code with your phone camera to download your photo strip!
            </p>
            <p className="qr-url">
              Or visit: <a href={downloadUrl} target="_blank" rel="noopener noreferrer">
                {downloadUrl.length > 50 ? downloadUrl.substring(0, 50) + '...' : downloadUrl}
              </a>
            </p>
            <button className="direct-download-button" onClick={handleDirectDownload}>
              💾 Direct Download
            </button>
          </div>
        </div>
      )}
    </div>
  );
}

export default PhotoDisplay;