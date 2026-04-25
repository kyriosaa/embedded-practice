import Button from "../components/Button";
import {
  GiBroadDagger,
  GiCash,
  GiTavernSign,
  GiStopSign,
  GiGems,
} from "react-icons/gi";

function ButtonPage() {
  return (
    <div>
      <div>
        <Button primary rounded className="mb-1">
          <GiBroadDagger />
          Start Game
        </Button>
      </div>
      <div>
        <Button success rounded className="mb-1">
          <GiCash />
          Buy Now
        </Button>
      </div>
      <div>
        <Button warning rounded className="mb-1">
          <GiTavernSign />
          See Deal
        </Button>
      </div>
      <div>
        <Button danger rounded className="mb-1">
          <GiStopSign />
          Hide Ads
        </Button>
      </div>
      <div>
        <Button secondary rounded className="mb-1">
          <GiGems />
          +20 Gems
        </Button>
      </div>
    </div>
  );
}

export default ButtonPage;
