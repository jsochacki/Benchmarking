int i, j, parity_accumulator;
   for (j = 0; j < Num_Parity_Bits; j++)
   {
      parity_accumulator = 0;
      for (i= 1; i < Num_Check_Nodes; i++)
      {
         parity_accumulator += encoded_bits[Check_Nodes[j].Bit_Nodes[i].index];
      }

      if (parity_accumulator & 1)
      {
         encoded_bits[Num_Info_Bits + j] = 1;
      }
      else
      {
      encoded_bits[Num_Info_Bits + j] = 0;
      }
   }
