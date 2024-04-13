<h1>MPEG Transport Stream Parser</h1>
<pre>
Done:
  - Header:
    - sync_byte
    - transport_error_indicator
    - payload_unit_start_indicator
    - transport_priority
    - PID
    - transport_scrambling_control
    - adaptation_field_control
  
  - Adaptation field:
    - adaptation_field_length
    - discontinuity_indicator
    - random_access_indicator
    - elementary_stream_priority_indicator
    - PCR_flag
    - OCPR_flag
    - splicing_point_flag
    - transport_private_data_flag
    - adaptation_field_extension_flag

TBD:
- Adaptation field:
  - program_clock_reference_base
  - program_clock_reference_extension
  - original_program_clock_reference_base
  - original_program_clock_reference_extension

- Payload (PES)
</pre>