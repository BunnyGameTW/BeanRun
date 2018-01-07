<GameFile>
  <PropertyGroup Name="ObstacleNode" Type="Node" ID="04e1edec-47c0-4aff-bc33-b4eca3f68039" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="35" Speed="1.0000">
        <Timeline ActionTag="-324085503" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="35" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-1201466197" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="8" Tween="False" Value="False" />
          <BoolFrame FrameIndex="16" Tween="False" Value="True" />
          <BoolFrame FrameIndex="25" Tween="False" Value="False" />
          <BoolFrame FrameIndex="32" Tween="False" Value="True" />
          <BoolFrame FrameIndex="35" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="124026228" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_00.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="4" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_01.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="8" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_02.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_03.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="16" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_04.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="20" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_05.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="25" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_06.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="29" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_07.png" Plist="scene101.plist" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="124026228" Property="VisibleForFrame">
          <BoolFrame FrameIndex="29" Tween="False" Value="True" />
          <BoolFrame FrameIndex="35" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="979431659" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_00.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="4" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_01.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="8" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_02.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_03.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="16" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_04.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="20" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_05.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="25" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_06.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="29" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame2_07.png" Plist="scene101.plist" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="979431659" Property="VisibleForFrame">
          <BoolFrame FrameIndex="29" Tween="False" Value="True" />
          <BoolFrame FrameIndex="35" Tween="False" Value="False" />
        </Timeline>
      </Animation>
      <ObjectData Name="oRoot" Tag="10" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="oShadow" ActionTag="360119928" Tag="24" IconVisible="False" LeftMargin="-65.6425" RightMargin="-71.3575" TopMargin="78.5452" BottomMargin="-101.5452" ctype="SpriteObjectData">
            <Size X="137.0000" Y="23.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="2.8575" Y="-90.0452" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="trishadow.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="oBody" ActionTag="-324085503" Tag="26" IconVisible="False" LeftMargin="-85.4293" RightMargin="-82.5707" TopMargin="-69.1414" BottomMargin="-74.8586" ctype="SpriteObjectData">
            <Size X="168.0000" Y="144.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-1.4293" Y="-2.8586" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="triblock.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="o1" Visible="False" ActionTag="923949697" Tag="29" IconVisible="True" LeftMargin="-0.0001" RightMargin="0.0001" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="o1" ActionTag="-1201466197" VisibleForFrame="False" Tag="25" IconVisible="False" LeftMargin="-85.5015" RightMargin="-85.4985" TopMargin="-92.5757" BottomMargin="-75.4243" ctype="SpriteObjectData">
                <Size X="171.0000" Y="168.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0015" Y="8.5757" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="triouter.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-0.0001" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="o2" ActionTag="-11350162" Tag="30" IconVisible="True" LeftMargin="9.9999" RightMargin="-9.9999" TopMargin="10.0000" BottomMargin="-10.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="o2" ActionTag="124026228" VisibleForFrame="False" Tag="27" IconVisible="False" LeftMargin="-130.0000" RightMargin="-110.0000" TopMargin="-121.0000" BottomMargin="-99.0000" ctype="SpriteObjectData">
                <Size X="240.0000" Y="220.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-10.0000" Y="11.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="flame1_07.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="9.9999" Y="-10.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="o3" Visible="False" ActionTag="-1936423263" Tag="31" IconVisible="True" LeftMargin="19.9998" RightMargin="-19.9998" TopMargin="20.0000" BottomMargin="-20.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="o3" ActionTag="979431659" VisibleForFrame="False" Tag="28" IconVisible="False" LeftMargin="-108.0000" RightMargin="-72.0000" TopMargin="-95.0000" BottomMargin="-85.0000" ctype="SpriteObjectData">
                <Size X="180.0000" Y="180.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-18.0000" Y="5.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="flame2_07.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="19.9998" Y="-20.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>