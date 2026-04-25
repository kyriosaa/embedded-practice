import { useState, useEffect } from 'react';
import './css/Countdown.css';

function Countdown({ onComplete, photoNumber }) {
  const [count, setCount] = useState(3);

  useEffect(() => {
    if (count > 0) {
      const timer = setTimeout(() => {
        setCount(count - 1);
      }, 1000);
      return () => clearTimeout(timer);
    } else {
      onComplete();
      setCount(3); // Reset for next photo
    }
  }, [count, onComplete]);

  return (
    <div className="countdown">
      <div className="countdown-number">
        {count > 0 ? count : '📸'}
      </div>
      <div className="countdown-text">
        Photo {photoNumber} of 2
      </div>
    </div>
  );
}

export default Countdown;