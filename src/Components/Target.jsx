import "../Styles/target.css";

function Target(props) {
  return (
    <div className={`targetContainer ${props.disabled ? "disabled" : ""}`}>
      <div className="targetCircle white">
        <div className="targetCircle black">
          <div className="targetCircle blue">
            <div className="targetCircle red">
              <div className="targetCircle yellow"></div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}

export default Target;
