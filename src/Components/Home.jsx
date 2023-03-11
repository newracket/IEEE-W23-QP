import "../Styles/home.css";
import Target from "./Target";
import Switch from "react-switch";
import { useState } from "react";
import { useNavigate } from "react-router-dom";

function Home() {
  const [timedChecked, setTimedChecked] = useState(false);
  const [time, setTime] = useState(30);
  const [targets, setTargets] = useState(3);
  const navigate = useNavigate();

  const handleToggle = (c) => {
    setTimedChecked(c);
  };

  const handleTimeInput = (e) => {
    setTime(parseInt(e.target.value));
  };

  const handleTargetsInput = (e) => {
    setTargets(parseInt(e.target.value));
  };

  const handlePlay = () => {
    navigate("/game", { state: { timedChecked, time, targets } });
  };

  return (
    <div className="homeContainer">
      <div className="titleContainer">
        <h1 className="title">Game</h1>
      </div>

      <Target />

      <div className="selectionsContainer">
        <div className="selection">
          <label className="option" htmlFor="timed">
            Timed
          </label>
          <Switch
            checked={timedChecked}
            onChange={handleToggle}
            uncheckedIcon={false}
            checkedIcon={false}
            id="timed"
          />
          {timedChecked ? (
            <input
              type="number"
              className="numberInput"
              id="time"
              min={0}
              defaultValue={30}
              onChange={handleTimeInput}
            />
          ) : (
            ""
          )}
        </div>

        <div className="selection">
          <label className="option" htmlFor="targets">
            # Targets
          </label>

          <input
            type="number"
            className="numberInput"
            id="targets"
            min={0}
            max={6}
            defaultValue={3}
            onChange={handleTargetsInput}
          />
        </div>
      </div>

      <button onClick={handlePlay} className="play">
        Play
      </button>
    </div>
  );
}

export default Home;
