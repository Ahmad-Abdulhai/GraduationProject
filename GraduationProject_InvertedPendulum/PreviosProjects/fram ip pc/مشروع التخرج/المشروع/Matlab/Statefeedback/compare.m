load ip1
subplot(211)
hold on
plot(ys.time,ys.signals.values,'r')
plot(y.time,y.signals.values)
title('Position')
subplot(212)
hold on
plot(ys.time,y1s.signals.values,'r')
plot(y.time,y1.signals.values)
title('Angle')
% subplot(313)
% hold on
% plot(ys.time,y2s.signals.values,'r')
% plot(y.time,y2.signals.values)
% title('Control')