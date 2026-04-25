import { useState } from 'react';
import Camera from './Camera';
import FrameSelector from './FrameSelector';
import PhotoDisplay from './PhotoDisplay';
import './css/HomeScreen.css';

function HomeScreen({ setPhotos, setSelectedFrame }) {
  const [photos, setLocalPhotos] = useState([]);
  const [selectedFrame, setLocalSelectedFrame] = useState('frame1');
  const [showPhotos, setShowPhotos] = useState(false);

  const handlePhotosCapture = (capturedPhotos) => {
    setLocalPhotos(capturedPhotos);
    setPhotos(capturedPhotos);
    setShowPhotos(true);
  };

  const handleFrameSelect = (frame) => {
    setLocalSelectedFrame(frame);
    setSelectedFrame(frame);
  };

  const handleRetakePhotos = () => {
    setLocalPhotos([]);
    setShowPhotos(false);
  };

  return (
    <div className="home-screen">
      <h1 className="title">📸 Photo Booth</h1>
      
      {!showPhotos ? (
        <div className="camera-section">
          <FrameSelector 
            selectedFrame={selectedFrame}
            onFrameSelect={handleFrameSelect}
          />
          <Camera 
            onPhotosCapture={handlePhotosCapture}
            selectedFrame={selectedFrame}
          />
        </div>
      ) : (
        <PhotoDisplay 
          photos={photos}
          selectedFrame={selectedFrame}
          onRetake={handleRetakePhotos}
        />
      )}
    </div>
  );
}

export default HomeScreen;