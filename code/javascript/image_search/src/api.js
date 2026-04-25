import axios from "axios";

const searchImages = async (term) => {
  const response = await axios.get("https://api.unsplash.com/search/photos", {
    headers: {
      // Using Unsplash's API
      Authorization: "Client-ID _Aj9taJ2EjN2uPy_NJtQktMriZSF7CiqhPkSKegKJ_4",
    },
    params: {
      query: term,
    },
  });

  return response.data.results;
};

export default searchImages;
