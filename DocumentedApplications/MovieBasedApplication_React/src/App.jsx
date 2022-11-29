import React, { useEffect, useState } from "react";
import './App.css';
import MovieCard from "./MovieCard";
import SearchIcon from './search.svg';


/*
    Author: Faisal Chowdhury (MD A Faisal) 
    
    this is a demo application so normally the api keys will be hidden on the backend and i would use node.js to do this
*/

 //7164c63e
const api_ulr = 'http://www.omdbapi.com?apikey=7164c63e'
/* const movie1 = {
    "Title": "Italian Spiderman",
    "Year": "2007",
    "imdbID": "tt2705436",
    "Type": "movie",
    "Poster": "https://m.media-amazon.com/images/M/MV5BYjFhN2RjZTctMzA2Ni00NzE2LWJmYjMtNDAyYTllOTkyMmY3XkEyXkFqcGdeQXVyNTA0OTU0OTQ@._V1_SX300.jpg"
} */
    



const App =() =>{
    
    const [movies, setMovies] = useState([]); //useState default value is an empty array
    const [searchTerm, setSearchTerm] = useState('');
    
    
    const searchMovies = async (title) =>{
        
        //  template string uses   `` and not ''
        const response = await fetch(`${api_ulr}&s=${title}`);
        const data = await response.json();
        
        setMovies(data.Search);    
    }
    
    

    useEffect(()=> {
        searchMovies('Batman');
        
    }, []);
    
    
    return(
        
    <div className="app">
        <h1>MovieCapital</h1>
        
        <div className="search">
            <input placeholder="Search for movies" value ={searchTerm} 
            
            onChange={(e)=> setSearchTerm(
                e.target.value
            )}/>
            
            <img src = {SearchIcon} alt="search" onClick={(e) =>searchMovies(`${searchTerm}`)}/>     
        </div>
        
        {
            
            movies.length > 0 
                ? (
                    
                    <div className="container">
                    
                        {movies.map((movie) => (
                            
                            <MovieCard movie={movie} />        
                        
                        ))}; 
                    </div>
                    
                ) :
                (
                    <div className="empty">
                        <h2>No movies found</h2>        
                    </div>
                    
                    
                )
            
        }
        
        
        
        
    </div>
            
    
        
    );
}

export default App;