function varargout = rtwinfbk_rtw_info_hook(varargin)
% RTWINFBK_RTW_INFO_HOOK - Target specific hook file for
% providing RTW the necessary information regarding this
% target.


Action    = varargin{1};
modelName = varargin{2};

switch Action
 case 'wordlengths'
  
  varargout{1} = rtwhostwordlengths(modelName);
  
 case 'cImplementation'
  
  varargout{1} = rtw_host_implementation_props(modelName);
  
 otherwise
  % Properly accommodate future releases of Real-Time Workshop
  varargout = [];
  
end


