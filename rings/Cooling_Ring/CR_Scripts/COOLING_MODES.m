classdef COOLING_MODES < Simulink.IntEnumType
    % MATLAB enumeration class definition generated from template
    %   to track the active leaf state of ModeSelectionRing/ModeSelectionRing/ModeSelectionRing.
    
    enumeration
        OFF(0),
		LOW(1),
        MEDIUM(2),
        HIGH(3),
        FULL(4)
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = COOLING_MODES.OFF;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Auto';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'enumeration to track the last passed startup state of the MSR';
        end

        function fileName = getHeaderFile()
            % GETHEADERFILE  Returns path to header file if non-empty.
            fileName = '';
        end

        function flag = addClassNameToEnumNames()
            % ADDCLASSNAMETOENUMNAMES  Indicate whether code generator applies the class name as a prefix
            %                          to the enumeration.
            flag = true;
        end

    end

end