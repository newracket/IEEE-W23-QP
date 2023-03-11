const { WebSocketServer } = require("ws");
const http = require("http");
const fs = require("fs");

const GAMEMODE_TXT_PATH = "C:\\Users\\airha\\IEEE-W23-QP\\src\\gamemode.txt";
const TARGETS_TXT_PATH = "targets.txt";

const server = http.createServer();
const ws = new WebSocketServer({ server });
const port = 8000;
server.listen(port, () => {
  console.log(`WebSocket server is running on port ${port}`);
});

const connections = [];
ws.on("connection", (socket) => {
  console.log("New connection!");
  connections.push(socket);
  sendEnabledTargets();

  socket.on("error", console.error);

  socket.on("message", (message) => {
    handleMessage(JSON.parse(message.toString()));
  });

  // socket.send("Hello from the backend!");
});

function handleMessage(args) {
  console.log(args);

  if (args.modify === "gamemode") {
    const dataToWrite = `${args.start ? args.targets : 0}`;

    console.log(dataToWrite);
    fs.writeFileSync(GAMEMODE_TXT_PATH, dataToWrite);
  }
}

fs.watchFile(TARGETS_TXT_PATH, sendEnabledTargets);

function sendEnabledTargets() {
  const targetsEnabled = getEnabledTargets();

  connections.forEach((socket) => {
    socket.send(JSON.stringify({ targetsEnabled }));
  });
}

function getEnabledTargets() {
  const data = fs
    .readFileSync("targets.txt", "utf-8")
    .replaceAll("\r", "")
    .split("\n");
  const targetsEnabled = data.map((e) => e === "1");

  return targetsEnabled;
}

// hi