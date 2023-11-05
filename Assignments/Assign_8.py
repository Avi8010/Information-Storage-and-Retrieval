import requests
from pprint import pprint

def weather_data(query):
    res=requests.get('http://Api.openweathermap.org/data/2.5/weather?'+query+'&APPID=enter app id&units=metric');
    print(res)
    return res.json()

def print_weather(result,city):
    print("{}'s temp: {}°C ".format(city,result['main']['temp']))
    print("wind speed: {} m/s ".format(result['wind']['speed']))
    print("description: {} ".format(result['weather'][0]['description']))
    print("weather: {} ".format(result['weather'][0]['main']))

def main():
    city=input('Enter the city name:')
    print()
    try:
        query='q='+city;
        w_data=weather_data(query);
        print_weather(w_data,city)
        print()
    except:
        print('City not found...')

if __name__=='__main__':
    main()
