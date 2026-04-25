// This project initially has photos of animals. However, I decided to replace them with photos of Pokemon just for fun.
import "./App.css";
import "bulma/css/versions/bulma-no-dark-mode.min.css";
import { useState } from "react";
import PokemonShow from "./PokemonShow";

function getRandomPokemon() {
  const pokemons = [
    "venusaur",
    "charizard",
    "blastoise",
    "butterfree",
    "beedrill",
    "pidgeot",
    "raticate",
    "fearow",
    "arbok",
    "raichu",
    "sandslash",
    "nidoqueen",
    "nidoking",
    "clefable",
    "ninetales",
    "wigglytuff",
    "golbat",
    "vileplume",
    "parasect",
    "venomoth",
    "dugtrio",
    "persian",
    "golduck",
    "primeape",
    "arcanine",
    "poliwrath",
    "alakazam",
    "machamp",
    "victreebel",
    "tentacruel",
    "golem",
    "rapidash",
    "slowbro",
    "magneton",
    //"farfetchd",
    "dodrio",
    "dewgong",
    "muk",
    "cloyster",
    "gengar",
    "onix",
    "hypno",
    "kingler",
    "electrode",
    "exeggutor",
    "marowak",
    "hitmonlee",
    "hitmonchan",
    "lickitung",
    "weezing",
    "rhydon",
    "chansey",
    "tangela",
    "kangaskhan",
    "seadra",
    "seaking",
    "starmie",
    //"mr.mime",
    "scyther",
    "jynx",
    "electabuzz",
    "magmar",
    "pinsir",
    "tauros",
    "gyarados",
    "lapras",
    "ditto",
    "vaporeon",
    "jolteon",
    "flareon",
    "porygon",
    "omastar",
    "kabutops",
    "aerodactyl",
    "snorlax",
    "articuno",
    "zapdos",
    "moltres",
    "dragonite",
    "mew",
    "mewtwo",
  ];

  return pokemons[Math.floor(Math.random() * pokemons.length)];
}

function App() {
  const [pokemons, setPokemons] = useState([]);

  const handleClick = () => {
    setPokemons([...pokemons, getRandomPokemon()]);
  };

  const renderedPokemons = pokemons.map((pokemon, index) => {
    return <PokemonShow type={pokemon} key={index} />;
  });

  return (
    <div className="app">
      <section className="hero is-danger">
        <div className="hero-body">
          <button className="title" onClick={handleClick}>
            Add Random Pokemon
          </button>
        </div>
      </section>

      <div className="div">
        <div className="column">Pokemon sprites created by: u/Red_O_Zone</div>
      </div>

      <div className="container">
        <section className="section">
          <div className="columns">
            <div className="pokemon-list is-4">{renderedPokemons}</div>
          </div>
        </section>
      </div>
    </div>
  );
}

export default App;
