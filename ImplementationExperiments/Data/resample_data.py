import pandas as pd

df = pd.read_csv("data.csv")
df = df.drop_duplicates()
# df.to_csv("dedup.csv")
print(df.columns)
df['timestamp (ms)'] = pd.to_timedelta(df['timestamp (ms)'], unit='ms')
df.set_index('timestamp (ms)', inplace=True)
df = df.resample('10ms').interpolate()
df.index = df.index.map(lambda td : td.total_seconds())
df.index.name = 'timestamp_s'
df.rename(columns={
    'accx (m/s^2)':'accx',
    'accy (m/s^2)':'accy',
    'accz (m/s^2)':'accz',
    'gyrox (rad/s)':'gyrox',
    'gyroy (rad/s)':'gyroy',
    'gyroz (rad/s)':'gyroz',
    'pressure (kPa)':'pressure'}, inplace=True)

df.to_csv("100hz.csv")
