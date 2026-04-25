import "./ImageShow.css";

function ImageShow({ image }) {
  return (
    <div className="card" overflow="scroll">
      <div className="card-image">
        <figure className="image">
          <img src={image.urls.small} alt={image.urls.small} />
        </figure>
      </div>

      <div className="card-content">
        <p>{image.alt_description}</p>
      </div>
    </div>
  );
}

export default ImageShow;
