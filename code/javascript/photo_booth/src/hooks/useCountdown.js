import { useState, useEffect } from 'react';

const useCountdown = (initialCount = 3) => {
  const [count, setCount] = useState(initialCount);
  const [isActive, setIsActive] = useState(false);

  useEffect(() => {
    let timer = null;

    if (isActive && count > 0) {
      timer = setInterval(() => {
        setCount((prevCount) => prevCount - 1);
      }, 1000);
    } else if (count === 0) {
      setIsActive(false);
    }

    return () => clearInterval(timer);
  }, [isActive, count]);

  const startCountdown = () => {
    setIsActive(true);
    setCount(initialCount);
  };

  const resetCountdown = () => {
    setIsActive(false);
    setCount(initialCount);
  };

  return { count, isActive, startCountdown, resetCountdown };
};

export default useCountdown;