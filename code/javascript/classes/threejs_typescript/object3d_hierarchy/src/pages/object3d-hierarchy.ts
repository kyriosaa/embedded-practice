import "../style.css";
import * as THREE from "three";
import { OrbitControls } from "three/addons/controls/OrbitControls.js";
import Stats from "three/addons/libs/stats.module.js";
import { GUI } from "dat.gui";

const scene = new THREE.Scene();
scene.add(new THREE.AxesHelper(5));

const camera = new THREE.PerspectiveCamera(
  75,
  window.innerWidth / window.innerHeight,
  0.1,
  1000
);
camera.position.set(4, 4, 4);

const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

const controls = new OrbitControls(camera, renderer.domElement);
controls.target.set(8, 0, 0);
controls.update();

const light = new THREE.PointLight(0xffffff, 400);
light.position.set(10, 10, 10);
scene.add(light);

const object1 = new THREE.Mesh(
  new THREE.SphereGeometry(),
  new THREE.MeshPhongMaterial({ color: 0xff0000 })
);
object1.position.set(4, 0, 0);
scene.add(object1);
object1.add(new THREE.AxesHelper(5));

const object2 = new THREE.Mesh(
  new THREE.SphereGeometry(),
  new THREE.MeshPhongMaterial({ color: 0x00ff00 })
);
object2.position.set(4, 0, 0);
object1.add(object2);
object2.add(new THREE.AxesHelper(5));

const object3 = new THREE.Mesh(
  new THREE.SphereGeometry(),
  new THREE.MeshPhongMaterial({ color: 0x0000ff })
);
object3.position.set(4, 0, 0);
object2.add(object3);
object3.add(new THREE.AxesHelper(5));

window.addEventListener("resize", () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});

const gui = new GUI();
const object1Folder = gui.addFolder("Object1 (Red Ball)");
object1Folder.add(object1.position, "x", 0, 10, 0.01).name("X Position");
object1Folder
  .add(object1.rotation, "x", 0, Math.PI * 2, 0.01)
  .name("X Rotation");
object1Folder.add(object1.scale, "x", 0, 2, 0.01).name("X Scale");
object1Folder.open();
const object2Folder = gui.addFolder("Object2 (Green Ball)");
object2Folder.add(object2.position, "x", 0, 10, 0.01).name("X Position");
object2Folder
  .add(object2.rotation, "x", 0, Math.PI * 2, 0.01)
  .name("X Rotation");
object2Folder.add(object2.scale, "x", 0, 2, 0.01).name("X Scale");
object2Folder.open();
const object3Folder = gui.addFolder("Object3 (Blue Ball)");
object3Folder.add(object3.position, "x", 0, 10, 0.01).name("X Position");
object3Folder
  .add(object3.rotation, "x", 0, Math.PI * 2, 0.01)
  .name("X Rotation");
object3Folder.add(object3.scale, "x", 0, 2, 0.01).name("X Scale");
object3Folder.open();

const stats = new Stats();
document.body.appendChild(stats.dom);

const debug = document.getElementById("debug") as HTMLDivElement;

function animate() {
  requestAnimationFrame(animate);

  renderer.render(scene, camera);

  const object1WorldPosition = new THREE.Vector3();
  object1.getWorldPosition(object1WorldPosition);
  const object2WorldPosition = new THREE.Vector3();
  object2.getWorldPosition(object2WorldPosition);
  const object3WorldPosition = new THREE.Vector3();
  object3.getWorldPosition(object3WorldPosition);

  debug.innerText =
    "Red\n" +
    "Local Pos X : " +
    object1.position.x.toFixed(2) +
    "\n" +
    "World Pos X : " +
    object1WorldPosition.x.toFixed(2) +
    "\n" +
    "\nGreen\n" +
    "Local Pos X : " +
    object2.position.x.toFixed(2) +
    "\n" +
    "World Pos X : " +
    object2WorldPosition.x.toFixed(2) +
    "\n" +
    "\nBlue\n" +
    "Local Pos X : " +
    object3.position.x.toFixed(2) +
    "\n" +
    "World Pos X : " +
    object3WorldPosition.x.toFixed(2) +
    "\n";

  stats.update();
}

animate();
