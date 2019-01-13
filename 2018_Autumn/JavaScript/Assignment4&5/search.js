let searchB = document.querySelector("#searchB");
let div = document.querySelector("#searchDiv");

// When Search Button Clicked
searchB.addEventListener("click", function() {
  // Clear the Div first
  while(div.firstChild){
    div.removeChild(div.firstChild);
  }

  // Grab user input
  let title = document.querySelector("#title").value;
  let result = document.createElement("h2");
  result.innerHTML = `Result of ${title} <br>`;
  div.appendChild(result);
  if (title.length < 3) { // Prevent single alphabet or spaces to be searched 
    let par = document.createElement("p");
    par.innerHTML = `Enter 3 letters minimum<br>`;
    div.appendChild(par);
  }
  else {
  // Search and match between user input and DB
    for(let i = 1; i <= 10; i++) {
      let api = new XMLHttpRequest;
      let url = "https://api.themoviedb.org/3/movie/popular?api_key=f5d2a77ac4646c3a1689cb3e8cc1ff0c&language=en-US&page="+i;
      api.open("GET", url);
      api.send();
      api.addEventListener("readystatechange", function(){
        if(api.readyState == 4) {
          let all = JSON.parse(api.responseText);

          for(let j = 0; j < all.results.length; j++) {
            let movie = all.results[j];
            let titleNoCase = new RegExp(title, "ig");
            if(titleNoCase.test(movie.title)) {
              showMovie(movie);
            }
          }
        }
      });
    }
    // Let user know, there is no matched movie
    if(div.childNodes.length === 0) {
      let par = document.createElement("p");
      par.innerHTML = `Nothing Found<br>`;
      div.appendChild(par);
    }
  }
})

// Show detailed info of Movie
function showMovie(movie) {
  let oneInfo = document.createElement("p");
  let img = document.createElement("img");
  img.setAttribute("src", "https://image.tmdb.org/t/p/w185_and_h278_bestv2/"+ movie.poster_path);

  let title = document.createElement("h2");
  title.innerHTML = movie.title;
  let contents = document.createElement("p");
  contents.innerHTML = "User Score: " + movie.vote_average + "<br>" + "Released: " + movie.release_date + "<br>" + "<em>"+ movie.overview;
  
  oneInfo.appendChild(title);
  oneInfo.appendChild(img);
  oneInfo.appendChild(contents);
  
  let videoURL = "https://api.themoviedb.org/3/movie/" + movie.id + "/videos?api_key=f5d2a77ac4646c3a1689cb3e8cc1ff0c&language=en-US";
  let link = new XMLHttpRequest;
  link.open("GET", videoURL);
  link.send();
  link.addEventListener("readystatechange", function(){
    if(link.readyState == 4) {
      let info = JSON.parse(link.responseText);
      let movieKey = info.results[0].key;
      let movieURL = "https://www.youtube.com/embed/" + movieKey;
      let video = document.createElement("iframe");
      video.setAttribute("width", "420");
      video.setAttribute("height", "315");
      video.setAttribute("src", movieURL);
      oneInfo.appendChild(video);
    }
  });
  div.appendChild(oneInfo);
}






