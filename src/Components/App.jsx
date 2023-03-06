import "../Styles/app.css";
import Home from "./Home";
import Game from "./Game";
import { BrowserRouter, Route, Routes } from "react-router-dom";

function App() {
  return (
    <div className="container">
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/game" element={<Game />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
