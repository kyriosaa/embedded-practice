interface TypeGuardsProps {
  value: Image | User;
}

interface Image {
  src: string;
}

interface User {
  username: string;
}

function isUser(value: Image | User): value is User {
  return "username" in value;
}

function TypeGuards({ value }: TypeGuardsProps) {
  function logOutput() {
    if (isUser(value)) {
      return value.username;
    } else {
      return value.src;
    }
  }

  return <div>{logOutput()}</div>;
}

export default TypeGuards;
