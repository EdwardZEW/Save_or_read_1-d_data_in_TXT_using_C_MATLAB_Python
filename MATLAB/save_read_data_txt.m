% Matlab R2022a
% Keywords:
%    save or read data in txt
%    copy strings and arrays
%    format of read and print
% By Edward Z. Wu 2023-02-10

%% read

folder = 'E:\MATLABproject\';
% txtformat="%.8f\n"; % .8f won't work in reading.
txtformat="%f\n";
fpath=[folder 'sig_read.txt'];
fileID = fopen(fpath,'r');
sig_read=fscanf(fileID,txtformat);
fclose(fileID);

%% save

sig_write=sig_read;

txtformat="%.8f\n";
fpath=[folder 'sig_write.txt'];
fileID = fopen(fpath,'w');
fprintf(fileID,txtformat,sig_write);
fclose(fileID);