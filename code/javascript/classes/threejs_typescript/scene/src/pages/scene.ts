import "../style.css";
import * as THREE from "three";
import Stats from "three/addons/libs/stats.module.js";
import { OrbitControls } from "three/addons/controls/OrbitControls.js";
import { GUI } from "dat.gui";
import { sceneA } from "../components/sceneA";
import { sceneB } from "../components/sceneB";
import { sceneC } from "../components/sceneC";

const camera = new THREE.PerspectiveCamera(
  75,
  window.innerWidth / window.innerHeight,
  0.1,
  1000
);
camera.position.set(0, 0, 1.5);
camera.lookAt(0, 0, 0);

const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

window.addEventListener("resize", () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});

new OrbitControls(camera, renderer.domElement);
const geometry = new THREE.BoxGeometry();
const material = new THREE.MeshNormalMaterial({ wireframe: true });

const cube = new THREE.Mesh(geometry, material);
sceneA.add(cube);

const stats = new Stats();
document.body.appendChild(stats.dom);

// Scene control
let activeScene = sceneA;
const setScene = {
  sceneA: () => {
    activeScene = sceneA;
  },
  sceneB: () => {
    activeScene = sceneB;
  },
  sceneC: () => {
    activeScene = sceneC;
  },
};

// Rotation control
let isRotating = true;
const rotationControl = {
  toggleRotation: () => {
    isRotating = !isRotating;
  },
};

// Center Camera to Object Control
let isCentered = false;
const lookAtObject = {
  toggleLookAt: () => {
    isCentered = !isCentered;
  },
};

// GUI
const gui = new GUI();

const sceneFolder = gui.addFolder("Scene");
sceneFolder.add(setScene, "sceneA").name("Skybox");
sceneFolder.add(setScene, "sceneB").name("Solid Black");
sceneFolder.add(setScene, "sceneC").name("Grid Texture");

const cubeFolder = gui.addFolder("Cube");
cubeFolder.add(rotationControl, "toggleRotation").name("Toggle Auto-Rotation");
cubeFolder.add(cube.rotation, "x", 0, Math.PI * 2).name("X");
cubeFolder.add(cube.rotation, "y", 0, Math.PI * 2).name("Y");
cubeFolder.add(cube.rotation, "z", 0, Math.PI * 2).name("Z");
cubeFolder.open();

const cameraFolder = gui.addFolder("Camera");
cameraFolder.add(lookAtObject, "toggleLookAt").name("Center Camera on Object");
cameraFolder.add(camera.position, "x", -20, 20).name("X");
cameraFolder.add(camera.position, "y", -20, 20).name("Y");
cameraFolder.add(camera.position, "z", -20, 20).name("Z");
cameraFolder.open();

function animate() {
  requestAnimationFrame(animate);

  if (isRotating) {
    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;
  }

  if (isCentered) {
    camera.lookAt(0, 0, 0);
  }

  renderer.render(activeScene, camera);

  stats.update();
}

animate();
