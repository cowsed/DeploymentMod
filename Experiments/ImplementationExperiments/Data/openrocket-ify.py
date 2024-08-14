import pandas as pd
import numpy as np

df = pd.read_csv("100hz.csv")
print(df.columns)
header = '''# Omen Flight 2024
#
# Time (s),Vertical acceleration (m/s²),Lateral acceleration (m/s²),Roll rate (°/s),Pitch rate (°/s),Yaw rate (°/s),Air pressure (mbar),Air temperature (°C)
# Event IGNITION occurred at t=0 seconds
# Event LAUNCH occurred at t=0 seconds
'''

df['timestamp_s'] = df['timestamp_s'] - df['timestamp_s'].min()
df['timestamp_s'] = df['timestamp_s']
df['lateral2'] = df['accx'] * df['accx'] + df['accy'] * df['accy']
df['lateral'] = np.sqrt(df['lateral2'])
df['temp'] = 35
df['pressure'] = df['pressure'] * 10

with open("test.csv", 'w') as f:
    f.write(header)
    df[['timestamp_s', 'accz', 'lateral', 'gyrox', 'gyroy',
        'gyroz', 'pressure', 'temp']].to_csv(f, index=False, header=False)
