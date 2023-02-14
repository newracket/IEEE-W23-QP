import "../Styles/home.css";
import Target from "./Target";

function Home() {
  return (
    <div className="homeContainer">
      <div className="titleContainer">
        <h1 className="title">Game</h1>
      </div>

      <Target />

      <div className="selectionContainer">
        <select name="gamemode" className="selection" id="gamemode">
          <option value="timed">Timed</option>
          <option value="multiple">Multiple Targets</option>
        </select>

        <button className="play">Play</button>
      </div>
    </div>
  );
}

export default Home;
