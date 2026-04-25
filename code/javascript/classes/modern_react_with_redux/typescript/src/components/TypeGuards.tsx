interface Image {
  src: string;
}

interface TypeGuardsProps {
  value: string | number | string[] | Image;
}

function TypeGuards({ value }: TypeGuardsProps) {
  function logOutput() {
    if (typeof value === "string") {
      return value.toUpperCase();
    }
    if (typeof value === "number") {
      return Math.round(value);
    }
    if (Array.isArray(value)) {
      return value.join("");
    }
    if (typeof value === "object" && !Array.isArray(value)) {
      return value.src;
    }
  }

  return <div>{logOutput()}</div>;
}

export default TypeGuards;
