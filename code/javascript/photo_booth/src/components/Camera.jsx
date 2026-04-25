import { useRef, useEffect, useState } from 'react';
import Countdown from './Countdown';
import './css/Camera.css';

function Camera({ onPhotosCapture, selectedFrame }) {
  const videoRef = useRef(null);
  const canvasRef = useRef(null);
  const [isCapturing, setIsCapturing] = useState(false);
  const [capturedPhotos, setCapturedPhotos] = useState([]);
  const [currentPhotoIndex, setCurrentPhotoIndex] = useState(0);

  useEffect(() => {
    startCamera();
    return () => {
      stopCamera();
    };
  }, []);

  const startCamera = async () => {
    try {
      const stream = await navigator.mediaDevices.getUserMedia({ 
        video: { width: 640, height: 480 } 
      });
      if (videoRef.current) {
        videoRef.current.srcObject = stream;
      }
    } catch (error) {
      console.error('Error accessing camera:', error);
    }
  };

  const stopCamera = () => {
    if (videoRef.current && videoRef.current.srcObject) {
      const tracks = videoRef.current.srcObject.getTracks();
      tracks.forEach(track => track.stop());
    }
  };

  const capturePhoto = () => {
    const canvas = canvasRef.current;
    const video = videoRef.current;
    const context = canvas.getContext('2d');
    
    // Maintain original video dimensions
    canvas.width = video.videoWidth;
    canvas.height = video.videoHeight;
    context.save();
    context.scale(-1, 1);
    context.drawImage(video, -video.videoWidth, 0, video.videoWidth, video.videoHeight);
    context.restore();
    
    return canvas.toDataURL('image/png');
  };

  const handleStartCapture = () => {
    setIsCapturing(true);
    setCapturedPhotos([]);
    setCurrentPhotoIndex(0);
  };

  const handleCountdownComplete = () => {
    const photo = capturePhoto();
    const newPhotos = [...capturedPhotos, photo];
    setCapturedPhotos(newPhotos);
    
    if (newPhotos.length < 2) {
      setCurrentPhotoIndex(newPhotos.length);
    } else {
      setIsCapturing(false);
      onPhotosCapture(newPhotos);
    }
  };

  return (
    <div className="camera-container">
      <div className="camera-window">
        <video 
          ref={videoRef} 
          autoPlay 
          muted 
          className="camera-video flipped"
        />
        <canvas 
          ref={canvasRef} 
          style={{ display: 'none' }}
        />
        
        {isCapturing && (
          <div className="countdown-overlay">
            <Countdown 
              onComplete={handleCountdownComplete}
              photoNumber={currentPhotoIndex + 1}
            />
          </div>
        )}
      </div>
      
      {!isCapturing && (
        <button 
          className="capture-button"
          onClick={handleStartCapture}
        >
          Take 2 Photos
        </button>
      )}
      
      {capturedPhotos.length > 0 && capturedPhotos.length < 2 && (
        <p className="photo-progress">
          Photo {capturedPhotos.length} of 2 captured
        </p>
      )}
    </div>
  );
}

export default Camera;