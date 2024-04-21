"""演習1-3: 天気取得の演習"""
import urllib.request
import json

# 指定先の web から データを引っ張ってくる
city = "130000"

# 読み取り先 2021 年度から気象庁へ変更
# 下記13000 は東京の場所コード，場所を見たい場合は http://www.jma.go.jp/bosai/common/const/area.json を参照
src = "https://www.jma.go.jp/bosai/forecast/data/forecast/%s.json"

print("URL:", src % (city))

with urllib.request.urlopen(src % (city)) as f:
    data_str = f.read()  # データ取得

# JSON レコードの解析
data = json.loads(data_str)

# 以下に演習の答えを書いていくこと

day3 = data[0]
day3series = day3['timeSeries']
w_predicts = day3series[0]
pred_dates = w_predicts['timeDefines']
tokyo_weather = w_predicts['areas'][0]
print("天気予報（３日間）", tokyo_weather['area']['name'])
for d, w in zip(pred_dates, tokyo_weather['weathers']):
    print(d, w)