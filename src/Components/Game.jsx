import Target from "./Target";
import Timer from "./Timer";
import { useLocation, useNavigate } from "react-router-dom";
import "../Styles/game.css";
import { useState } from "react";
import useWebSocket from "react-use-websocket";

const WS_URL = "ws://127.0.0.1:8000";
const ws = new WebSocket(WS_URL);

function Game() {
  const { state } = useLocation();
  let { timedChecked, time, targets } = state;

  const navigate = useNavigate();

  const [targetValues, setTargetValues] = useState(
    [...Array(targets)].map((_) => false)
  );
  const [gameStarted, setGameStarted] = useState(false);
  const [score, setScore] = useState(0);

  const { sendMessage } = useWebSocket(WS_URL, {
    onOpen: () => console.log("Websocket Connected!"),
    onMessage: (event) => console.log(event.data),
  });

  ws.onopen = () => {
    console.log("Websocket Connected!");
  };

  ws.onmessage = (event) => {
    handleMessage(event);
  };

  function handleMessage(event) {
    const targetsEnabled = JSON.parse(event.data)?.targetsEnabled;
    if (targetsEnabled === undefined) return;

    if (gameStarted) {
      const targetsKnocked = targetValues.filter(
        (e, i) => e && !targetsEnabled[i]
      );
      setScore(score + targetsKnocked.length);
    }

    setTargetValues(targetsEnabled.slice(0, targets));
  }

  function setGameState(gameState) {
    setGameStarted(gameState);
    sendMessage(
      JSON.stringify({
        modify: "gamemode",
        start: gameState,
        targets,
      })
    );
  }

  function backToHome() {
    navigate("/");
  }

  return (
    <div className="outerGameContainer">
      <button className="back" onClick={backToHome}>
        Back to Home
      </button>

      <div className="gameContainer">
        <div className="timerContainer">
          <Timer
            timedChecked={timedChecked}
            seconds={time}
            setGameState={setGameState}
            setScore={setScore}
          />

          <div className="scoreContainer">
            <div className="scoreText">Score: {score}</div>
          </div>
        </div>

        <div className="targetsContainer">
          {targetValues.map((e, i) => (
            <div className="targetItem" key={i}>
              <Target disabled={!e} />
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}

export default Game;
