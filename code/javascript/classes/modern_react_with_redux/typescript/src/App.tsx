import "./App.css";
import ColorPicker from "./components/ColorPicker";
import TypeGuards from "./components/TypeGuards";

function App() {
  return (
    <>
      <div>
        <ColorPicker
          colors={["red", "green", "blue"]}
          handleColorSelect={(color: string) => console.log(color)}
        />
      </div>
      <br />
      <div>
        <TypeGuards value={1234.5678} />
      </div>
    </>
  );
}

export default App;
