let index = localStorage.getItem("poster");
let div = document.querySelector("#movieDetail");

let xhr = new XMLHttpRequest;
xhr.open("GET", "https://api.themoviedb.org/3/movie/now_playing?api_key=f5d2a77ac4646c3a1689cb3e8cc1ff0c&language=en-US&page=1");
xhr.send();
xhr.addEventListener("readystatechange", function() {
  if(xhr.readyState == 4) {
    let all = JSON.parse(xhr.responseText);  
    showMovie(all);
  }
});

function showMovie(all) {
  let movie = all.results[index];
  let img = document.createElement("img");
  img.setAttribute("src", "https://image.tmdb.org/t/p/w185_and_h278_bestv2/"+ movie.poster_path);

  let title = document.createElement("h2");
  title.innerHTML = movie.title;
  let contents = document.createElement("p");
  contents.innerHTML = "User Score: " + movie.vote_average + "<br>" + "Released: " + movie.release_date + "<br>" + "<em>"+ movie.overview;
  
  div.appendChild(title);
  div.appendChild(img);
  div.appendChild(contents);
  
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
      div.appendChild(video);
    }
  });
}
