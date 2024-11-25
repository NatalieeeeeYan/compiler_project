declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@N = global i32 0
@newline = global i32 0
define i32 @mod( i32 %r100, i32 %r102 ) {
bb1:
  %r145 = add i32 0, 0
  %r146 = add i32 %r100, 0
  %r147 = add i32 0, 0
  %r148 = add i32 %r102, 0
  %r107 = sdiv i32 %r146, %r148
  %r109 = mul i32 %r107, %r148
  %r110 = sub i32 %r146, %r109
  ret i32 %r110
}

define i32 @split( i32 %r111, i32* %r113 ) {
bb2:
  %r151 = add i32 0, 0
  %r152 = add i32 %r111, 0
  %r153 = add i32 0, 0
  %r115 = load i32, i32* @N
  %r116 = sub i32 %r115, 1
  %r154 = add i32 %r116, 0
  br label %bb_while_5_14_cond

bb_while_5_14_cond:
  %r155 = phi i32 [ %r152, %bb2 ], [ %r157, %bb_while_5_14_whilestms ]
  %r156 = phi i32 [ %r154, %bb2 ], [ %r158, %bb_while_5_14_whilestms ]
  %r118 = icmp ne i32 %r156, -1
  br i1 %r118, label %bb_while_5_14_whilestms, label %bb_while_5_14_bre

bb_while_5_14_whilestms:
  %r120 = getelementptr i32, i32* %r113, i32 %r156
  %r122 = call i32 @mod(i32 %r155, i32 10)
  store i32 %r122, i32* %r120
  %r124 = sdiv i32 %r155, 10
  %r157 = add i32 %r124, 0
  %r126 = sub i32 %r156, 1
  %r158 = add i32 %r126, 0
  br label %bb_while_5_14_cond

bb_while_5_14_bre:
  ret i32 0
}

define i32 @main( ) {
bb3:
  call void @_sysy_starttime(i32 26)
  store i32 4, i32* @N
  store i32 10, i32* @newline
  %r162 = add i32 0, 0
  %r163 = add i32 0, 0
  %r129 = alloca [ 4 x i32 ]
  %r164 = add i32 1478, 0
  %r131 = getelementptr [4 x i32 ], [4 x i32 ]* %r129, i32 0, i32 0
  %r132 = call i32 @split(i32 %r164, i32* %r131)
  %r165 = add i32 %r132, 0
  %r166 = add i32 0, 0
  %r167 = add i32 0, 0
  br label %bb_while_5_36_cond

bb_while_5_36_cond:
  %r168 = phi i32 [ %r166, %bb3 ], [ %r170, %bb_while_5_36_whilestms ]
  %r169 = phi i32 [ %r167, %bb3 ], [ %r171, %bb_while_5_36_whilestms ]
  %r135 = icmp slt i32 %r169, 4
  br i1 %r135, label %bb_while_5_36_whilestms, label %bb_while_5_36_bre

bb_while_5_36_whilestms:
  %r137 = getelementptr [4 x i32 ], [4 x i32 ]* %r129, i32 0, i32 %r169
  %r138 = load i32, i32* %r137
  %r170 = add i32 %r138, 0
  call void @putint(i32 %r170)
  %r140 = load i32, i32* @newline
  call void @putch(i32 %r140)
  %r142 = add i32 %r169, 1
  %r171 = add i32 %r142, 0
  br label %bb_while_5_36_cond

bb_while_5_36_bre:
  call void @_sysy_stoptime(i32 42)
  ret i32 0
}

