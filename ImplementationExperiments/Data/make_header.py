import pandas as pd

pdef = '''
struct packet {
    double t;
    double ax, ay ,az;
    double press;
};
'''
print(pdef)


print('packet packets[] = {')
df = pd.read_csv("100hz.csv").set_index('timestamp_s')
for t, row in df.iterrows():
    print(f"    {{{row.name}, {row.accx}, {row.accy}, {row.accz}, {row.pressure}}},")

print('};')

print(f"long num_packets = {len(df)};")