const axios = require('axios');
const url = 'https://jsonmock.hackerrank.com/api/weather/search?name=';

async function getInfo(keyword, i) {
  let res = await axios.get(url + keyword + '&page=' + i);
  let response = res.data;

  let arr = response.data;

  let ans = [];

  arr.forEach((element) => {
    let s = element.status;
    let temp = [element.name, (element.weather).split(" degree")[0], (s[0]).split("Wind: ")[1].split("Kmph")[0], (s[1]).split("Humidity: ")[1].split("%")[0]];

    ans.push(temp);
  });

  return ans;
}

async function getWeatherData(keyword) {
  let res = await axios.get(url + keyword);
  let response = res.data;

  let pages = response.total_pages;

  let arr = [];

  for (let i = 1; i <= pages; i++) {
    arr.push(getInfo(keyword, i));
  }

  let a = await Promise.all(arr);

  let ans = [];

  a.forEach((temp) => {
    temp.forEach((element) => {
      let p = String(element[0] + ", " + element[1] + ", " + element[2] + ", " + element[3]);
      ans.push(p);
    });
  });

  return ans;
}

(async () => {
  try {
    const keyword = 'all'; // Replace with the keyword you want to search for
    const result = await getWeatherData(keyword);
    console.log(result);
  } catch (error) {
    console.error('Error:', error);
  }
})();
