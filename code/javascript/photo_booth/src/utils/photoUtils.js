import { createRef } from 'react';

export const capturePhoto = (videoRef) => {
  const canvas = createRef();
  const context = canvas.current.getContext('2d');
  context.drawImage(videoRef.current, 0, 0, canvas.current.width, canvas.current.height);
  return canvas.current.toDataURL('image/png');
};

export const processPhotos = (photos) => {
  return photos.map(photo => {
    // Add any processing logic here if needed
    return photo;
  });
};