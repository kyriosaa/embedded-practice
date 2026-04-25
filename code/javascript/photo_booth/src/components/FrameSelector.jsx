import './css/FrameSelector.css';

function FrameSelector({ selectedFrame, onFrameSelect }) {
  const frames = [
    { id: 'frame1', name: 'frame1', preview: '/src/assets/frame1.png' },
    { id: 'frame2', name: 'frame2', preview: '/src/assets/frame2.png' },
    { id: 'frame3', name: 'frame3', preview: '/src/assets/frame3.png' },
    { id: 'frame4', name: 'frame4', preview: '/src/assets/frame4.png' },
    { id: 'frame5', name: 'frame5', preview: '/src/assets/frame5.png' },
    { id: 'frame6', name: 'frame6', preview: '/src/assets/frame6.png' },
    { id: 'frame7', name: 'frame7', preview: '/src/assets/frame7.png' },
  ];

  return (
    <div className="frame-selector">
      <h3>Choose a Frame:</h3>
      <div className="frame-options">
        {frames.map(frame => (
          <button
            key={frame.id}
            className={`frame-option ${selectedFrame === frame.id ? 'selected' : ''}`}
            onClick={() => onFrameSelect(frame.id)}
          >
            <img 
              src={frame.preview} 
              alt={frame.name}
              className="frame-preview"
            />
            <span className="frame-name">{frame.name}</span>
          </button>
        ))}
      </div>
    </div>
  );
}

export default FrameSelector;