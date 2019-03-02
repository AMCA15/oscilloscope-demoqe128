buffer = 4096;

data = fread(s,buffer,'int8');
databyte = int8(data);

% Sync the data
start = find(databyte > 0, 1);
syncData = databyte(start:end-mod((buffer-start),4)-1);

% Convert to unsigned
syncData = typecast(syncData, 'uint8');

% Resulting data block size
blocksize = length(syncData);

byte0 = syncData(1:4:end);
byte1 = syncData(2:4:end);
byte2 = syncData(3:4:end);
byte3 = syncData(4:4:end);


cha_d = bitget(byte1, 7);
chb_d = bitget(byte3, 7);

Mask_Ana(1:blocksize/4,1) = uint8(63);

cha_a_l = bitand(byte0, Mask_Ana);
cha_a_h = bitand(byte1, Mask_Ana);
chb_a_l = bitand(byte2, Mask_Ana);
chb_a_h = bitand(byte3, Mask_Ana);

t = 1:blocksize/4;

cha_a = uint16(cha_a_h)*64 + uint16(cha_a_l);
chb_a = uint16(chb_a_h)*64 + uint16(chb_a_l);

plot(t, cha_a, t, chb_a);
axis([0 1024 0 4096])
