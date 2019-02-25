start = find(data > 0, 1);
syncData = data(start:end-(5-start));


byte3 = syncData(1:4:end);
byte2 = syncData(2:4:end);
byte1 = syncData(3:4:end);
byte0 = syncData(4:4:end);


cha_d = bitget(byte1, 7, 'int8');
chb_d = bitget(byte3, 7, 'int8');
%cha_a_l = bitsliceget(byte2, 6);
%cha_a_h = bitsliceget(byte1, 6);
%cha_b_l = bitsliceget(byte2, 6);
%cha_b_h = bitsliceget(byte3, 6);