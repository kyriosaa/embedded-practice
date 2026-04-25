import "./PokemonShow.css";
import { useState } from "react";
import aerodactyl from "./images/aerodactyl.png";
import alakazam from "./images/alakazam.png";
import arbok from "./images/arbok.png";
import arcanine from "./images/arcanine.png";
import articuno from "./images/articuno.png";
import beedrill from "./images/beedrill.png";
import blastoise from "./images/blastoise.png";
import butterfree from "./images/chansey.png";
import chansey from "./images/chansey.png";
import charizard from "./images/charizard.png";
import clefable from "./images/clefable.png";
import cloyster from "./images/cloyster.png";
import dewgong from "./images/dewgong.png";
import ditto from "./images/ditto.png";
import dodrio from "./images/dodrio.png";
import dragonite from "./images/dragonite.png";
import dugtrio from "./images/dugtrio.png";
import electabuzz from "./images/electabuzz.png";
import electrode from "./images/electrode.png";
import exeggutor from "./images/exeggutor.png";
//import farfetchd from "./images/farfetchd.png";
import fearow from "./images/fearow.png";
import flareon from "./images/flareon.png";
import gengar from "./images/gengar.png";
import golbat from "./images/golbat.png";
import golduck from "./images/golduck.png";
import golem from "./images/golem.png";
import gyarados from "./images/gyarados.png";
import hitmonchan from "./images/hitmonchan.png";
import hitmonlee from "./images/hitmonlee.png";
import hypno from "./images/hypno.png";
import jolteon from "./images/jolteon.png";
import jynx from "./images/jynx.png";
import kabutops from "./images/kabutops.png";
import kangaskhan from "./images/kangaskhan.png";
import kingler from "./images/kingler.png";
import lapras from "./images/lapras.png";
import lickitung from "./images/lickitung.png";
import machamp from "./images/machamp.png";
import magmar from "./images/magmar.png";
import magneton from "./images/magneton.png";
import marowak from "./images/marowak.png";
import mew from "./images/mew.png";
import mewtwo from "./images/mewtwo.png";
import moltres from "./images/moltres.png";
//import mrmime from "./images/mrmime.png";
import muk from "./images/muk.png";
import nidoking from "./images/nidoking.png";
import nidoqueen from "./images/nidoqueen.png";
import ninetales from "./images/ninetales.png";
import omastar from "./images/omastar.png";
import onix from "./images/onix.png";
import parasect from "./images/parasect.png";
import persian from "./images/persian.png";
import pidgeot from "./images/pidgeot.png";
import pinsir from "./images/pinsir.png";
import poliwrath from "./images/poliwrath.png";
import porygon from "./images/porygon.png";
import primeape from "./images/primeape.png";
import raichu from "./images/raichu.png";
import rapidash from "./images/rapidash.png";
import raticate from "./images/raticate.png";
import rhydon from "./images/rhydon.png";
import sandslash from "./images/sandslash.png";
import scyther from "./images/scyther.png";
import seadra from "./images/seadra.png";
import seaking from "./images/seaking.png";
import slowbro from "./images/slowbro.png";
import snorlax from "./images/snorlax.png";
import starmie from "./images/starmie.png";
import tangela from "./images/tangela.PNG";
import tauros from "./images/tauros.png";
import tentacruel from "./images/tentacruel.png";
import vaporeon from "./images/vaporeon.png";
import venomoth from "./images/venomoth.png";
import venusaur from "./images/venusaur.png";
import victreebel from "./images/victreebel.png";
import vileplume from "./images/vileplume.png";
import weezing from "./images/weezing.png";
import wigglytuff from "./images/wigglytuff.png";
import zapdos from "./images/zapdos.png";
import heart from "./images/heart.png";

const pokemonMap = {
  aerodactyl,
  alakazam,
  arbok,
  arcanine,
  articuno,
  beedrill,
  blastoise,
  butterfree,
  chansey,
  charizard,
  clefable,
  cloyster,
  dewgong,
  ditto,
  dodrio,
  dragonite,
  dugtrio,
  electabuzz,
  electrode,
  exeggutor,
  // farfetchd,
  fearow,
  flareon,
  gengar,
  golbat,
  golduck,
  golem,
  gyarados,
  hitmonchan,
  hitmonlee,
  hypno,
  jolteon,
  jynx,
  kabutops,
  kangaskhan,
  kingler,
  lapras,
  lickitung,
  machamp,
  magmar,
  magneton,
  marowak,
  mew,
  mewtwo,
  moltres,
  // mrmime,
  muk,
  nidoking,
  nidoqueen,
  ninetales,
  omastar,
  onix,
  parasect,
  persian,
  pidgeot,
  pinsir,
  poliwrath,
  porygon,
  primeape,
  raichu,
  rapidash,
  raticate,
  rhydon,
  sandslash,
  scyther,
  seadra,
  seaking,
  slowbro,
  snorlax,
  starmie,
  tangela,
  tauros,
  tentacruel,
  vaporeon,
  venomoth,
  venusaur,
  victreebel,
  vileplume,
  weezing,
  wigglytuff,
  zapdos,
};

function PokemonShow({ type }) {
  const [clicks, setClicks] = useState(0);

  const handleClick = () => {
    setClicks(clicks + 1);
  };

  return (
    <div className="pokemon-show" onClick={handleClick}>
      <img className="pokemon" alt="pokemon" src={pokemonMap[type]} />
      <img
        className="heart"
        alt="heart"
        src={heart}
        style={{ width: 0 + 10 * clicks + "px" }}
      />
    </div>
  );
}

export default PokemonShow;
