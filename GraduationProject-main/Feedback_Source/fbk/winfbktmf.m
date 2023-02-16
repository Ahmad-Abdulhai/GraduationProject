function [tmf,envVal] = winfbktmf
%WINFBKTMF Returns the "default" template makefile for use with rtwinfbk.tlc
%   $Revision: 1.51 $  $Date : $  $Author: ez (for qrts) $


% get the compiler set up by 'mex -setup'

[tmf,envVal] = get_tmf_for_target('winfbk');

% test if it is supported

switch(tmf)
case 'win_lcc.tmf'
  err = 'LCC';
case 'win_bc.tmf'
  err = 'Borland C/C++';
otherwise
  err = '';
end;

% print an error if it is not

if ~isempty(err)
  error(sprintf('%s compiler is not supported.\nPlease use ''mex -setup'' to set up Microsoft VC6.0 Profesional compilier .', err));
end;
