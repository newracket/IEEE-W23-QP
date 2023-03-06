import Target from "./Target";
import Timer from "./Timer";
import { useLocation } from "react-router-dom";
import "../Styles/game.css";

function Game() {
  const { state } = useLocation();
  let { timedChecked, time, targets } = state;

  targets = 5;

  console.log(timedChecked, time, targets);

  return (
    <div className="gameContainer">
      <div className="timerContainer">
        <Timer />
      </div>

      <div className="targetsContainer">
        {[...Array(targets)].map((e) => (
          <Target />
        ))}
      </div>
    </div>
  );
}

export default Game;
