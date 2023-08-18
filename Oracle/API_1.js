/*
 * Complete the 'getTotalGoals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING team
 *  2. INTEGER year
 */

const fetch = require('node-fetch');

async function getTotalGoals(team, year) {
    let total_pages_home = 1;
    let total_pages_visiting = 1;
    let ans = 0;
    let a
    for(let i = 1; i <= total_pages_home; i++) {
        let s = 'https://jsonmock.hackerrank.com/api/football_matches?year=' + year + "&team1=" + team + "&page=" + i;
        const response = await fetch(s);
        const temp = await response.json();
        total_pages_home = Number(temp.total_pages);
        let arr = temp.data;
        arr.forEach(item => {
           ans = ans + Number(item.team1goals);
        });
    }
    
    for(let i = 1; i <= total_pages_visiting; i++) {
        let s = 'https://jsonmock.hackerrank.com/api/football_matches?year=' + year + "&team2=" + team + "&page=" + i;
        const response = await fetch(s);
        const temp = await response.json();
        total_pages_visiting = Number(temp.total_pages);
        let arr = temp.data;
        arr.forEach(item => {
           ans = ans + Number(item.team2goals);
        }); 
    }
    
    return ans;   
}


// Fetch request
// fetch(apiUrl, {
//     method: method,
//     headers: headers,
//     body: requestBody // Include this if you're sending data in the request
//   })
//     .then(response => {