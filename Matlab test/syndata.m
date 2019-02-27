start = find(data > 0, 1);
syncData = data(start:end-(5-start));

%Extrae los bytes de la data
byte3 = syncData(1:4:end);
byte2 = syncData(2:4:end);
byte1 = syncData(3:4:end);
byte0 = syncData(4:4:end);

%Extrae los bits de los canales digitales
cha_d = bitget(byte1, 7, 'int8');
chb_d = bitget(byte3, 7, 'int8');

%Configura los bits para el canal analogico a
cha_a_l = dec2bin(typecast(byte0,'uint8'));
cha_a_low = cha_a_l(:,1:6);
cha_a_h = dec2bin(typecast(byte1,'uint8'));
cha_a_high = cha_a_h(:,1:6);
cah_a = [cha_a_high cha_a_low];

%Configura los bits para el canal analogico b
cha_b_l = dec2bin(typecast(byte2,'uint8'));
cha_b_low = cha_b_l(:,1:6);
cha_b_h = dec2bin(typecast(byte3,'uint8'));
cha_b_high = cha_b_h(:,1:6);
cha_b = [cha_b_high cha_b_low];
