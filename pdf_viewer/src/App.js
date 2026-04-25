import React from 'react';
import PdfViewer from './PdfViewer';

function App() {
  return (
    <div>
      <h1>PDF Viewer</h1>
      <PdfViewer url="/resume.pdf" />
    </div>
  );
}

export default App;
