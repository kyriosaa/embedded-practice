import { useEffect, useState } from "react";

function App() {
  const [counter, setCounter] = useState(0);

  // Let's say we want to console log the counter value
  // every single time any area inside the website is clicked...

  // -- Dont do this! --
  // useEffect(() => {
  //   document.body.onclick = () => {
  //     console.log(counter);
  //   };
  // }, []);

  // -- Do this! --
  useEffect(() => {
    document.body.onclick = () => {
      console.log(counter);
    };

    const cleanUp = () => {
      document.body.removeEventListener("click", listener);
    };

    return cleanUp;

    // Instead of leaving the array empty, add the counter variable inside of it
  }, [counter]);

  return (
    <div>
      <button onClick={() => setCounter(counter + 1)}>+ Increment</button>
      <div>Count: {counter}</div>
    </div>
  );
}

export default App;
