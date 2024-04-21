import urllib.request
import json

# 関数定義部 （ここを書くこと）
def Forecast(city='130000'):
    # None と書いてある行は消してから，関数定義をすること．
    # なお関数は天気概況の文字列を返す関数とすること
    src = "https://www.jma.go.jp/bosai/forecast/data/forecast/%s.json"
    print("URL:", src % (city))
    with urllib.request.urlopen(src % (city)) as f:
        data_str = f.read()  # データ取得
    # JSON レコードの解析
    data = json.loads(data_str)
    
    day3 = data[0]
    day3series = day3['timeSeries']
    w_predicts = day3series[0]
    pred_dates = w_predicts['timeDefines']
    todays_pred_dates = pred_dates[0]
    tokyo_weather = w_predicts['areas'][0]
    todays_tokyo_weather = tokyo_weather['weathers'][0]
    print("天気予報（本日）", tokyo_weather['area']['name'])
    print(todays_pred_dates, todays_tokyo_weather)

Forecast(140000)