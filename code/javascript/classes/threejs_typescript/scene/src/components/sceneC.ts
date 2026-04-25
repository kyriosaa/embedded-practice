// Texture Background
import * as THREE from "three";

const sceneC = new THREE.Scene();
sceneC.background = new THREE.TextureLoader().load(
  "https://sbcode.net/img/grid.png"
);

export { sceneC };
