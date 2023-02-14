import "../Styles/timer.css";
import { useEffect, useState } from "react";

function Timer() {
  const defaultMinutes = 10;
  const defaultSeconds = 0;

  const [timerStarted, setTimerStarted] = useState(false);
  const [minutes, setMinutes] = useState(defaultMinutes);
  const [seconds, setSeconds] = useState(defaultSeconds);

  useEffect(() => {
    let interval = null;

    if (timerStarted) {
      interval = setInterval(decrementTimer, 1000);
    } else {
      clearInterval(interval);
    }

    return () => clearInterval(interval);
  }, [timerStarted, decrementTimer]);

  function decrementTimer() {
    if (minutes === 0 && seconds === 1) {
      return setTimerStarted(false);
    }

    if (seconds === 0) {
      setMinutes(minutes - 1);
      setSeconds(59);
    } else {
      setSeconds(seconds - 1);
    }
  }

  function startPauseTimer() {
    setTimerStarted(!timerStarted);
  }

  function resetTimer() {
    setTimerStarted(false);
    setMinutes(defaultMinutes);
    setSeconds(defaultSeconds);
  }

  return (
    <div className="timer">
      <div className="textContainer">
        <div className="timerText">
          <span className="minutes">{minutes.toString().padStart(2, "0")}</span>
          :
          <span className="seconds">{seconds.toString().padStart(2, "0")}</span>
        </div>
      </div>

      <div className="buttonsContainer">
        <button className="startPause" onClick={startPauseTimer}>
          {timerStarted ? "Pause" : "Start"}
        </button>
        <button className="reset" onClick={resetTimer}>
          Reset
        </button>
      </div>
    </div>
  );
}

export default Timer;
