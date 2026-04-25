import { useState } from 'react';
import HomeScreen from './components/HomeScreen';
import './App.css';

function App() {
  const [photos, setPhotos] = useState([]);
  const [selectedFrame, setSelectedFrame] = useState(null);

  return (
    <div className="App">
      <HomeScreen 
        setPhotos={setPhotos} 
        setSelectedFrame={setSelectedFrame} 
      />
      {/* Additional components like PhotoDisplay can be added here */}
    </div>
  );
}

export default App;