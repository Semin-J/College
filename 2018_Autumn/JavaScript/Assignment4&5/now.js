let div = document.querySelector("#movieDiv");

let xhr = new XMLHttpRequest;
xhr.open("GET", "https://api.themoviedb.org/3/movie/now_playing?api_key=f5d2a77ac4646c3a1689cb3e8cc1ff0c&language=en-US&page=1");
xhr.send();
xhr.addEventListener("readystatechange", function() {
  if(xhr.readyState == 4) {
    let all = JSON.parse(xhr.responseText);  
    listMovies(all);

    document.addEventListener("readystatechange", function() {
      if(document.readyState === "complete") {
        grabIndex(all);
      }
    }) 
  }
});


function listMovies(all) {
  let ul = document.createElement("ul");
  for(let i = 0; i < all.results.length; i++) {
    let li = document.createElement("li");
    li.setAttribute("id", "movie"+i);
    let movie = all.results[i];

    let img = document.createElement("img");
    img.setAttribute("src", "https://image.tmdb.org/t/p/w185_and_h278_bestv2/"+ movie.poster_path);
    img.setAttribute("id", "img"+i);

    let anchor = document.createElement("a");
    anchor.setAttribute("target", "_blank");
    anchor.setAttribute("href", "detail.html");
    let title = document.createElement("h2");
    title.innerHTML = "Rank No." + (i+1) + " is " + movie.title;
    let contents = document.createElement("p");
    contents.innerHTML =
    `User Score: ${movie.vote_average}<br><br>
    Released: ${movie.release_date}<br><br>
    <em>${movie.overview}</em>
    `;
    
    li.appendChild(title);
    anchor.appendChild(img);
    li.appendChild(anchor);
    li.appendChild(contents);
    ul.appendChild(li);
  }
  div.appendChild(ul);
}

function grabIndex(all) {
  for(let i = 0; i < all.results.length; i++) {
    let tar = document.getElementById("img" + i);
    tar.addEventListener("click", function(){
      localStorage.poster = i;
    })
  }
}





