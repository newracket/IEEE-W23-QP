import Timer from "./Timer";
import "../Styles/app.css";
import Target from "./Target";

function App() {
  return (<div className="container">
      <div className="timerContainer">
        <Timer/>
      </div>

      <div className="targetsContainer">
        <Target/>
        <Target/>
        <Target/>
      </div>
    </div>);
}

export default App;
