import "./ImageShow.css";

function ImageShow({ image }) {
  return (
    <section>
      <img src={image.urls.small} alt={image.alt_description} />
      <div>{image.alt_description}</div>
    </section>
  );
}

export default ImageShow;
