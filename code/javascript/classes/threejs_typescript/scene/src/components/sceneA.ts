// Skybox
import * as THREE from "three";

const sceneA = new THREE.Scene();
sceneA.background = new THREE.CubeTextureLoader()
  .setPath("https://sbcode.net/img/")
  .load(["px.png", "nx.png", "py.png", "ny.png", "pz.png", "nz.png"]);

export { sceneA };
