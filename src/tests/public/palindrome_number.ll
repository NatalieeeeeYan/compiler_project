declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @mod( i32 %r100, i32 %r102 ) {
bb1:
  %r148 = add i32 0, 0
  %r149 = add i32 %r100, 0
  %r150 = add i32 0, 0
  %r151 = add i32 %r102, 0
  %r107 = sdiv i32 %r149, %r151
  %r109 = mul i32 %r107, %r151
  %r110 = sub i32 %r149, %r109
  ret i32 %r110
}

define i32 @palindrome( i32 %r111 ) {
bb2:
  %r155 = add i32 0, 0
  %r156 = add i32 %r111, 0
  %r113 = alloca [ 4 x i32 ]
  %r157 = add i32 0, 0
  %r158 = add i32 0, 0
  %r159 = add i32 0, 0
  br label %bb_while_5_12_cond

bb_while_5_12_cond:
  %r160 = phi i32 [ %r156, %bb2 ], [ %r162, %bb_while_5_12_whilestms ]
  %r161 = phi i32 [ %r159, %bb2 ], [ %r163, %bb_while_5_12_whilestms ]
  %r117 = icmp slt i32 %r161, 4
  br i1 %r117, label %bb_while_5_12_whilestms, label %bb_while_5_12_bre

bb_while_5_12_whilestms:
  %r119 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 %r161
  %r121 = call i32 @mod(i32 %r160, i32 10)
  store i32 %r121, i32* %r119
  %r123 = sdiv i32 %r160, 10
  %r162 = add i32 %r123, 0
  %r125 = add i32 %r161, 1
  %r163 = add i32 %r125, 0
  br label %bb_while_5_12_cond

bb_while_5_12_bre:
  %r126 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 0
  %r127 = load i32, i32* %r126
  %r128 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 3
  %r129 = load i32, i32* %r128
  %r130 = icmp eq i32 %r127, %r129
  br i1 %r130, label %bb25_19_next, label %bb_if_5_19_false

bb25_19_next:
  %r131 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 1
  %r132 = load i32, i32* %r131
  %r133 = getelementptr [4 x i32 ], [4 x i32 ]* %r113, i32 0, i32 2
  %r134 = load i32, i32* %r133
  %r135 = icmp eq i32 %r132, %r134
  br i1 %r135, label %bb_if_5_19_true, label %bb_if_5_19_false

bb_if_5_19_true:
  %r164 = add i32 1, 0
  br label %bb_if_5_19_end

bb_if_5_19_false:
  %r165 = add i32 0, 0
  br label %bb_if_5_19_end

bb_if_5_19_end:
  %r166 = phi i32 [ %r164, %bb_if_5_19_true ], [ %r165, %bb_if_5_19_false ]
  ret i32 %r166
}

define i32 @main( ) {
bb3:
  call void @_sysy_starttime(i32 30)
  %r169 = add i32 0, 0
  %r170 = add i32 1221, 0
  %r171 = add i32 0, 0
  %r140 = call i32 @palindrome(i32 %r170)
  %r172 = add i32 %r140, 0
  %r142 = icmp eq i32 %r172, 1
  br i1 %r142, label %bb_if_5_35_true, label %bb_if_5_35_false

bb_if_5_35_true:
  call void @putint(i32 %r170)
  br label %bb_if_5_35_end

bb_if_5_35_false:
  %r173 = add i32 0, 0
  call void @putint(i32 %r173)
  br label %bb_if_5_35_end

bb_if_5_35_end:
  %r174 = phi i32 [ %r172, %bb_if_5_35_true ], [ %r173, %bb_if_5_35_false ]
  %r175 = add i32 10, 0
  call void @putch(i32 %r175)
  call void @_sysy_stoptime(i32 47)
  ret i32 0
}

