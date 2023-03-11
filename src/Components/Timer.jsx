import "../Styles/timer.css";
import { useCallback, useEffect, useState } from "react";

function Timer(props) {
  let totalSeconds = parseInt(props.seconds);
  let changeFunction = decrementTimer;
  if (!props.timedChecked) {
    changeFunction = incrementTimer;
    totalSeconds = 0;
  }

  const defaultMinutes = Math.floor(totalSeconds / 60);
  const defaultSeconds = totalSeconds % 60;

  const [timerStarted, setTimerStarted] = useState(false);
  const [minutes, setMinutes] = useState(defaultMinutes);
  const [seconds, setSeconds] = useState(defaultSeconds);

  const setTimerState = useCallback(
    (timerState) => {
      props.setGameState(timerState);
      setTimerStarted(timerState);
    },
    [props]
  );

  useEffect(() => {
    let interval = null;

    if (timerStarted) {
      interval = setInterval(changeFunction, 1000);
    } else {
      clearInterval(interval);
    }

    return () => clearInterval(interval);
  }, [changeFunction, minutes, seconds, setTimerState, timerStarted]);

  function decrementTimer() {
    if (minutes === 0 && seconds === 1) {
      setSeconds(seconds - 1);
      return setTimerState(false);
    }

    if (seconds === 0) {
      setMinutes(minutes - 1);
      setSeconds(59);
    } else {
      setSeconds(seconds - 1);
    }
  }

  function incrementTimer() {
    if (seconds === 59) {
      setMinutes(minutes + 1);
      setSeconds(0);
    } else {
      setSeconds(seconds + 1);
    }
  }

  function startPauseTimer() {
    if (minutes === 0 && seconds === 0) {
      resetTimer();
    }

    setTimerState(!timerStarted);
  }

  function resetTimer() {
    setTimerState(false);
    setMinutes(defaultMinutes);
    setSeconds(defaultSeconds);
    props.setScore(0);
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
